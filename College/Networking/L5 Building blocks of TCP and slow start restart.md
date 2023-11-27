
#### Loss Detection Algorithms
- Retransmission Time Out
- Fast Retransmit
- Recent Acknowledgements
#### Loss Recovery Algorithms
- Fast recovery
- SACK 
- PRR (Default loss recovery algorithm in Linux)
#### Congestion Control
- Slow start
- AIMD, BIC
- CUBIC (default in Linux)
### Congestion control algorithms in TCP

##### What is congestion?
It is a network state during which the intermediate devices drop the packets because their buffers are full.
### Flow Control vs Congestion Control

#### Flow control
- TCP sender has to ensure that it does not fill the buffer in the TCP receiver 
- TCP receiver informs the sender about the space available in its buffer 
- 16-bit field in the TCP header is used for flow control 
- It is called rwnd (receiver window) or awnd (advertised window)

#### Congestion Control
- TCP sender had to detect whether it has filled up 'buffers at the intermediate devices' and if so then slow down the transmission rate
- No one informs the TCP sender about the state of the buffers at the intermediate devices
- For this the TCP sender estimates the state of the buffers at the intermediate devices and maintains a variable - congestion window (Unit is bytes or segments/packets)
- This estimate is for the entire path from the TCP sender to the TCP receiver.

### Slow start algorithm
- Start the process of estimating **cwnd** and quickly arrive at a decent estimate.
- Initial CWND  = 10 ( stored in a separate variable called initcwnd)
- CWND = The maximum packets that the sender can transmit without waiting for ACK
- One more important variable is used in TCP, which is called ‘inflight’ or ‘pipe’ 
	- inflight/pipe = the number of packets that have been sent but an ACK is not received for those packets i.e., they are ‘inflight’ or ‘in pipe’ between the sender and receiver 
	- inflight ≤ cwnd, but it is preferred than inflight = cwnd to utilize the network bandwidth

##### Algorithm
On every ACK

	cwnd = cwnd + 1
	inflight = inflight - 1 + 2

As we are sending 2 new segments (+2) and we got one ACK (-1)

- Thus, if all the segments are successfully ACKed, the cwnd will ‘eventually’ double.

**Key takeaway** 
- cwnd increases in a continuous manner, every time when an ACK arrives 
- TCP sender does not wait for ACKs of ‘all 10 segments’ to arrive to increase the cwnd.
	- This behavior will waste the network bandwidth because no new segments are sent till all ACKs arrive at the TCP sender 
	- It is preferred that ‘inflight’ is equal to ‘cwnd’, but in any case, it must ‘never be’ more than the cwnd.
- What is the terminating point of Slow Start algorithm?
	- When a packet drop occurs (i.e., the TCP sender does not get an ACK for a specific packet) 
	- When the algorithm reaches ‘Slow Start Threshold’. In Linux, it is called ‘ssthresh’
	- At the beginning of a TCP connection, ssthresh = ∞ 
	- ssthresh is updated when a packet drop occurs. It is updated as: ssthresh = cwnd ÷ 2

Time to reach the cwnd size of N 
![[Pasted image 20230902155649.png]]

### What is Slow Start Restart (SSR)?
SSR resets the cwnd of a TCP connection after it has been idle for a 'defined period' of time

	cwnd = 1
	ssthresh =  infinity

- This is done as the network conditions may have changed while the TCP connection was idle.
- cwnd is not updated during idle periods because there are ‘no incoming ACKs’. Hence, cwnd is a ‘stale estimate’ and does not reflect the ‘current network conditions’


