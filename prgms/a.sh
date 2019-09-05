## run commmand1, sleep for 1 minute and finally run command2 ## 
command1 && sleep 1m && command2
 
## sleep in bash for loop ##
for i in {1..10}
do
  ls
  sleep 5s
done
 
## run while loop to display date and hostname on screen ##
#while [ : ]
#do
 #   clear
#    tput cup 5 5
#    date
#    tput cup 6 5
#    echo "Hostname : $(hostname)"
  #  sleep 1
#done
