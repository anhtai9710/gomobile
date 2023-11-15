# This script builds gomobile and gobind and puts binaries to specified directory

# Read arguments
while getopts ":o:" opt; do
  case $opt in
    o)
      OUTPUT_DIR=$OPTARG
      ;;
    \?)
      echo "Invalid option: -$OPTARG" >&2
      exit 1
      ;;
  esac
done

# Get the directory of this script
WORKING_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

# Making sure output directory is specified
if [[ -z "$OUTPUT_DIR" ]]; then
  echo "Output directory is not specified. Use -o flag to specify it."
  exit 1
fi

# Get full path to output directory
OUTPUT_DIR="$(cd "$OUTPUT_DIR" && pwd)"

echo "Building gomobile and gobind to $OUTPUT_DIR..."

# Build gomobile
cd "$WORKING_DIR"/cmd/gomobile || exit
go build -o "$OUTPUT_DIR"

# Build gobind
cd "$WORKING_DIR"/cmd/gobind || exit
go build -o "$OUTPUT_DIR"

echo "Done"