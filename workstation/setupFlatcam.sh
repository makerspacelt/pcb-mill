#!/bin/sh -e
# "-e" exists on first error.

sudo apt-get update && sudo apt-get upgrade -y

DIR="Flatcam"
if [ -d "$DIR" ]; then
  # Take action if $DIR exists. #
  echo "Fetching changes ${DIR}..."
  cd ${DIR}
  git fetch
  git pull --rebase
else
    git clone https://github.com/AntumArk/Flatcam -b old_flatcam_pyqt5
    cd ${DIR}
fi

# install flatcam deps
chmod +x setup_ubuntu.sh
./setup_ubuntu.sh

# Create a link.
ln -s $PWD/flatcam /home/$USER/Desktop/flatcam