set -e
if [ ! -f make.bash ]; then
	echo 'all.bash must be run from $Compilor/src' 1>&2
	exit 1
fi
. ./make.bash "$@" --no-banner
bash run.bash --no-rebuild
../bin/go tool dist banner # print build info
