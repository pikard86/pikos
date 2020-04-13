echo "Running command: $1"

if [ $1 == "init" ]; then
./bin/init.sh
fi

if [ $1 == "clean" ]; then
./bin/clean.sh
fi


if [ $1 == "build" ]; then
./bin/build.sh
fi

if [ $1 == "run" ]; then
./bin/run.sh
fi

if [ $1 == "burn" ]; then
./bin/run.sh
fi