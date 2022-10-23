#!/bin/bash

sub_net='10.0.4.';
cnt=1;

while [ $cnt -le 255 ]
do
    echo "ping $sub_net$cnt"
    ping -c1 $sub_net$cnt &

    let cnt++
done
