
AIMD algorithm
- also known as congestion avoidance algorithm
- cwnd is increased by one segment on one RTT instead of on one ACK
- cwnd is decreased by half on detecting a packet loss

In slow start the window size is increasing rapidly at the beginning but it also makes the network congested fast which causes lot of bandwidth loss

#### Algorithm

On arrival of every ACK increment the cwnd by (1 / cwnd) and send 1 new segment in the network


