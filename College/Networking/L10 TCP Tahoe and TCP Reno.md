TCP Tahoe  = Slow Start + AIMD + Fast Retransmit

Slow Start phase 
- Lasts until Slow Start Threshold (ssthresh) 
- Initially, ssthresh is set to ∞. Subsequently, it adapts depending on the packet loss events 

AIMD 
- AI (increase cwnd by 1) and MD (reduce ssthresh to 50% of cwnd) 
- **Note: cwnd is ‘not’ reduced by 50%**

Fast Retransmit
- Triggered by three DACK's

**On packet loss detection reset cwnd to initcwnd**

So when ssthresh is reached then Slow start phase stops and AIMD phase starts and then if packet loss happens then the cwnd becomes initcwnd and then the slow start phase begins again and the same thing happens

![[Pasted image 20230923201154.png]]

### TCP Reno 
TCP Reno  = TCP Tahoe  + Fast Recovery

**Slow Start phase**
- Lasts until Slow Start Threshold (ssthresh) 
- Initially, ssthresh is set to ∞. Subsequently, it adapts depending on the packet loss events ○

**AIMD**
- AI (increase cwnd by 1) and MD (reduce ssthresh to 50% of cwnd)

**Fast Retransmit** 
- Triggered by 3 duplicate acknowledgements

On packet loss detection through Fast Retransmit 
- cwnd is reduced by 50%
On packet loss detection through RTO ■ Reset cwnd to initcwnd
![[Pasted image 20230923201437.png]]

![[Pasted image 20230923201507.png]]


#### Limitations of TCP Reno
Multiple times reduction of cwnd for packets lost in the same cwnd

#### Algorithm
TCP sender performs the 4 actions 
- Reduces the congestion window
- Reduces the slow start threshold
- Retransmits the lost packet
- Enters the 'Fast Recovery' phase

Half Window of silence
- The amount of time the sender has to wait for the inflight to become equal to cwnd is know as half window of silence
- New data packets are not transmitted during this period.
- Network resources are wasted because there is no new data transmission
