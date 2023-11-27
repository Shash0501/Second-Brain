
### RTO (Retransmission TimeOut)

- TCP sender waits for the RTO period for the ACK and if it hasn't received it by then it means the packet is dropped
- RTO is a function of RTT
	- it is calculated either on per packet basis or per cwnd basis

### Fast Retransmit
- Alternative to RTO, mainly avoids waiting for RTO to expire
- Leverages the **duplicate ACK** and **cumulative ACK** feature of TCP


Variables in RTO

SRTT -> smoothed RTT
RTTVar -> RTT Variation
RTO -> Retransmission Time out
R -> Current RTT measured


When RTT (R) is first measured
`SRTT = R`
`RTTVar = R / 2`
`RTO = SRTT + (K * RTTVar) { k = 4 }`

For all the subsequent RTT measurement 

`RTTVar = (1-b) * RTTVar + b * |SRTT-R| { b = 1/4 }`
`SRTT = (1-a) * SRTT + a * R  {a = 1/8}`
`RTO = SRTT + (K * RTTVar) { k = 4 }`

Max value of RTO = 60 sec and MIN value = 1 second

When a retransmission timer expires (i.e., an ACK is not received)
- Retransmit the lost packet
- RTO = RTO x 2 // this is called Binary Exponential Backoff (or BEB)

#### Karn's Algorithms
it avoids the ambiguity that arises while calculating the RTT of a 'retransmitted packet'
He suggested not to consider the RTT sample if the packer was a retransmitted one.

![[Pasted image 20230923192335.png]]


### Fast Retransmit Algorithm

It retransmits a dropped packet without waiting for the RTO to expire after receiving 3 duplicate ACK's

- It doesn't do it before cause the packet may have been dropped instead of getting delayed.
- It doesn't do it later (i.e. after 4 ACK's) because that may be too long and RTO may expire by then.
![[Pasted image 20230923192742.png]]

#### Limitations 
- May sometimes trigger the retransmission of a packet sooner that regular RTO mechanism.
- Not a complete replacement
	- It the packet is dropped at tail then it will have to rely on the expiration of RTO for it to know that the packet has dropped.
	- For this TLP - Tail Loss Probe addresses the problem of packets getting dropped at the tail of a TCP connection.
- 




