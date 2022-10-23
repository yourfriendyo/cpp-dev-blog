while :: do ps axj | head -1 && ps axj | grep myproc | grep -v grep sleep 1 : 
	echo "######################" :
done

