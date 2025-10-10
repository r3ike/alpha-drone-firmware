# Appunti

## **IMU pre-processing filtering**
### **PX4 Autopilot**
PX4 non filtra solo nel filtro di stato, ma anche prima, con una catena di preprocessing sull’IMU:
1. **Low Pass Filter su accelerometri e giroscopi:**
    - Tipicamente un filtro biquad o un Butterworth digitale
    - PX4 implementa un filtro biquadratico passa-basso del 2° ordine (Butterworth) in forma Direct Form II Transposed, molto efficiente per MCU.
2. **Notch filter:**
    - Filtrano frequenze specifiche di vibrazione (es. risonanza delle eliche o frame)
    - Utile nei droni: taglia i picchi a 120 Hz, 240 Hz ecc.
    - PX4 implementa un notch biquadratico (second order IIR), stessa struttura del LPF, ma con coeff. diversi:
3. **Clipping e outlier rejection:**
    - Se le accelerazioni superano certi limiti, vengono “scartate” per evitare che l’EKF si destabilizzi
---
### **Ardupilot**
1. **Low-pass filters (LPF)**
    - Filtri passa basso sui segnali degli accelerometri: parametro INS_ACCEL_FILTER controlla quanto aggressivo sia il taglio. 
    - Filtri LPF sui giroscopi: parametro INS_GYRO_FILTER. Serve a ridurre rumore ad alta frequenza che altrimenti costringerebbe il controller a reagire a “scossoni” indesiderati. 
    - Implementato come 1° o 2° ordine IIR, Butterworth semplificato.

2. **Notch Filters**
    - Implementato come filtro IIR del 2° ordine, identico alla struttura biquad di PX4.

3. **Harmonic Notch filter**
    - Notch dinamici applicati ai giroscopi per eliminare rumore a frequenze correlate al motore/eliche (rotazione / armoniche) 
    - Possono essere statici (frequenza fissa), basati sulla throttle, basati sulla telemetria ESC, o guidati da FFT durante il volo per trovare i picchi di rumore. 

4. **Configurazioni dinamiche / adattive**
    - ArduPilot ha modalità “throttle-based” per far variare il centro del notch in base all’impostazione della manetta (quando il motore gira più veloce o più lento) per tracciare la frequenza dominante. 
    - Modalità “In-Flight FFT”, che usa una FFT in tempo reale per identificare le frequenze di rumore dominanti e muovere il notch di conseguenza. 
--- 
**NB** :Entrambi non applicano notch agli accelerometri di default, perché:
- le vibrazioni negli accel vengono già smorzate dal LPF a bassa frequenza (30–80 Hz);
- l’accelerometro misura anche forze reali di manovra, quindi un notch rischierebbe di tagliare informazione utile.
---
### Come replicarli in un progetto
Per un progetto personale (es. su STM32 o Raspberry Pi):
- Usa LPF 2° ordine Butterworth per gli accelerometri.
- Usa LPF 1° ordine esponenziale per i giroscopi (meno ritardo).
- Implementa notch IIR per eliminare vibrazioni note (es. 120–240 Hz).
- Calcola coeff. digitali con scipy.signal.butter o iirnotch in Python, poi codificali in C.

---
### **LPF 2 Order Butterworth**
- Method: Start with the continuous-time transfer function of a 2nd-order low-pass Butterworth filter and convert it to a discrete-time transfer function using the bilinear transform, which involves the cutoff frequency (**omega _c**) and the sampling period (**T**).  
- Coefficients: From the discrete-time transfer function, determine the filter coefficients using the equations for the filter's difference equation.  
- Difference Equation: Apply the difference equation to your input signal to get the output signal.  
- State variables: Keep track of the previous two input and output values to compute the current output.     

## **IMU  filtering**