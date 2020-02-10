set -u
set -e

DIR=$1
FILE=$2

mkdir -p $DIR

touch $DIR/$FILE.cpp