Random early Discard

The main goal of RED is to 
- avoid congestion
- avoid the problem of global synchronisation
- avoid the problem of lock out
- maximize the power function (throughput / delay)


- Red runs on the output port but during the enqueue time
- Operates on arrival of each packet
- RED decides whether the incoming packet should be enqueued or dropped
	- Calculation of average queue length
	- Calculation of drop probability
	- Decision making logic

