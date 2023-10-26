animals=("a dog" "a cat" "a fish")
for i in ${animals[*]}; do echo $i; done

echo "break"

animals=("a dog" "a cat" "a fish")
for i in ${animals[@]}; do echo $i; done

echo "break"

animals=("a dog" "a cat" "a fish")
for i in "${animals[@]}"; do echo $i; done

echo "break"

animals=("a dog" "a cat" "a fish")
for i in "${animals[*]}"; do echo $i; done