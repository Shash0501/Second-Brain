
**Latency** - Time it takes for a data packet to travel from one point to another on a network.

**Bandwidth** - Maximum amount of data that can be transmitted over a network connection in a given amount of time. measured in bits per second

### Components of Latency (PTPQ)
1. Propagation Delay
	1. Time required for packet to travel from sender to receiver.
	2. physical distance between two endpoints (d) ÷ speed of light
2. Transmission Delay
	1. Time required to push all the packet's bits into the link.
	2. packet length / bandwidth of the link
3. Processing Delay
	1. Time required to process the packer header ( check for bit-level headers and determine the packet's destination)
	2. can be decreased by increasing bandwidth of the network
4. Queuing Delay
	1. Time the packet is waiting in the queue until it can be forwarded
	2. can be decreased by increasing the buffer size of router or have faster router
5. Queuing vs Transmission
	1.  The main difference between queuing delay and transmission delay is that queuing delay is caused by waiting in a queue, while transmission delay is caused by the physical process of transmitting the packet over the link. When a packet arrives at a router or switch, it is placed in a queue. The router or switch then processes the packets in the queue in order. The amount of time that a packet spends in the queue depends on the number of packets in the queue and the speed at which the router or switch can process them.

### Bandwidth vs Latency
Bandwidth matters in cases that involve bulk data transfers whereas roundtrip latency matters in cases of everyday browsing where we fetch hundreds of small resources from different hosts 

### Reducing the delays
1. Propagation Delay
	1. Improve the Refractive index of the medium
	2. Reduce the physical distance between two endpoints
		1. CDN (Content Distribution Networks)
2. Transmission Delay
	1. Reduce the packer length
		1. Not a good solution.
		2. Network overhead
		3. Large headers but small data
	2. Increase the bandwidth of the link
		1. Increasing the bandwidth only reduces one component of the latency
3. Processing Delay
	1. better algorithms for faster IP lookup (LPM longest prefix match)
	2. Multiprocessing ( process the packets in parallel )
4. Queuing Delay
	1. Do not keep buffers 
		1. Probably a solution but buffers are necessary in time sensitive applications as without buffers packets will get dropped and it will effect performance
	2. Keep buffers small
		1. Keeping buffers small will again cause packet loss and proper utilization of the link capacity cannot be done.
	3. Deploy 'Active Queue Management' (RED, CoDel)

### Latency Requirements
1. **Latency Sensitive Traffic ( interactive)**
	1. Minimum latency desired
	2. Ex : VoIP, Audio/Video Conferencing, online games
2. **Latency Tolerant Traffic ( Elastic, non-critical)**
	1. Max **throughput** desired
	2. Ex : File Transfers, updates etc.
3. **Streaming Content Traffic ( timely)**
	1. ‘Lesser variations in the delay’ and ‘Consistent throughput’ is desired for this type of traffic.
	2. Ex : Netflix, Hotstar, Amazon Prime Video, Internet radio, and others. 