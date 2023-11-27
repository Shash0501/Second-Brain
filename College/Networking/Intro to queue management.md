### Architecture of a Router

**Input Port** 
- Line termination - Convert electrical signals to digital data
- Data link processing - Performs function like error detection and frame synchronization, validates the data packets
- Queuing and scheduling - to manage the incoming traffic
	- Forwarding - input port in conjunction to switching port forwards the packet to the appropriate output ports


Queue management algorithms can be classified into passive queue management and active queue management algorithms

- Passive
	- After the queue is full
	- reactive in nature
- Active 
	- Operate before the queue is full
	- proactive in nature


#### Congestion at the Input ports
Suppose 1 packet is arriving at each input port in one unit of time. There are arriving N packets at input ports in one unit time. The speed of switching fabric is less than N packets per unit of time, so it will not be able to forward these N packets arriving at input ports to the output ports. Say switch fabric processes N/2 packets and the remaining N/2 packets are queued in some of the input ports. If these packets keep coming at input ports then soon the buffer at input ports will fill up and congestion state will exist and packets will get dropped.

#### Congestion at the output ports
Suppose all N packets are destined to go to output port-1 then in one unit of time, the output port will transmit 1 packet and queue the rest of n-1 packets into the buffer. Again n packets will be received to the same output port-1 then it will again queue n-1 packets and transmit 1 packet. Soon, the buffer will be full and packet loss will start occurring, this is the congestion state at output ports.

### PQM
- Drop Tail
	- Drops packet from the tail of the queue.
	- Acts like a simple FIFO queue.
- Drop Head
	- Drops the packet from the head of the queue.
	- It makes space for newly coming packets by making dropping the packets from the head of the queue.
	- DropHead ensures fairness
	- The long-lasting flows like bit-torrent consume the majority of the bandwidth and other applications become slower. The packets of long-lasting application will keep filling the buffer and short-lasting flows will get dropped by DropTail, but DropHead will make space for them by dropping the packets of long-lasting flows
- Random drop
	- Drops packet from random positions
	- What is the advantage of using Random Drop? If we drop the packets from the head, then we are hurting the long-lasting flows. If we drop the packets from the tail, we are hurting the time-sensitive flows. So, to be fair with both types of flows, we randomly select one packet and drop it. Let fate decide which packet will get dropped and which flow will get hurt.


### Limitations of PQM

#### Global Synchronization

- Multiple TCP flows start at ethe same time
- CWND of all conn increase
- Drop tail causes many packtes to be dropped at the same time
- All theh flows reduce theor CWND simultaneously
- This adds jitter Frequent periods of link ‘overutilization’ and ‘underutilization’.

#### Lock Out
- Drop tail allows few flows to monopolize the queue space

#### Buffer Bloat
Memory prices have fallen sharply. This problem existed earlier also but never became serious because of the memory size and price. In 2005, the maximum RAM capacity was 256 MB, but today it is 8 GB minimum. Hence, buffering capacity has increased. Excessive buffering leads to ‘high queuing delays. It was reported that queuing delays sometimes rise so much that TCP RTO expires! Time-sensitive applications are the worst affected ones due to bufferbloat.


