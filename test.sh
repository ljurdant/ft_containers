make test
ts=$(date +%s%N)
./ft_containers > f
echo "FT:"$((($(date +%s%N) - $ts)/1000000))"ms"
ts=$(date +%s%N)
./std_containers > s
echo "STL:"$((($(date +%s%N) - $ts)/1000000))"ms"
make fclean
rm f s

