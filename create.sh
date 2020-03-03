set -u
set -e

DIR=$1
mkdir -p $DIR

for ((i = 2; i <= $#; i++ )); do
    FILE=${!i}
    echo "$FILE created"
    touch $DIR/$FILE
done


