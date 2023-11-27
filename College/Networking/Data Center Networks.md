#### Fundamental changes in the TCP
RTO cannot be in the order of ms because the overall RTT in data centers is in 100's of microseconds 

### Challenges

#### TCP Incast
TLA - Top level aggregator
MLA - Middle level aggregator

#### TCP Outcast
- Happens when two sets of flows compete for the same output port
- Elephant flows lead to port blackout for mice flows
- Occurs in data centers that employ switches with droptail queue discipline

#### Queue buildup and Buffer pressure
- Elephant flows keep the buffers full, hence there is no room to accommodate bursts
- Mice flows are either dropped or encounter high queuing delays

#### Pseudo congestion effect
- Virtualization is a key technology for cloud computing
- Hypervisors are crucial to schedule several VM's to gain access to physical servers
- Hypervisor scheduling latency can be very high sometimes!
	- Starvation of a VM 
	- Long wait times for a VM 
- Due to high scheduling latency, a packet may not get processed soon enough
	- RTO expires 
	- TCP sender considers this as an indication of high congestion and resets the cwnd