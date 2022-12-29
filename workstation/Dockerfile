FROM nfqlt/php74-dev

ENV XAUTHORITY /home/project/.Xauthority
ADD build /build
WORKDIR /home/project/Flatcam
## for apt to be noninteractive
ENV DEBIAN_FRONTEND noninteractive
ENV DEBCONF_NONINTERACTIVE_SEEN true

## preesed tzdata, update package index, upgrade packages and install needed software
RUN echo "tzdata tzdata/Areas select Europe" > /tmp/preseed.txt; \
    echo "tzdata tzdata/Zones/Europe select Vilnius" >> /tmp/preseed.txt; \
    debconf-set-selections /tmp/preseed.txt && \
    apt-get update && \
    apt-get install -y tzdata --no-install-recommends

RUN apt-get update && apt-get install -y --no-install-recommends \
    git \
    python3-pip\
    sudo\
    python3-setuptools\
    nano\
    build-essential\
    xserver-xorg \
    xinit \
    # From setup_ubuntu.sh . Makes caching faster.
    libfreetype6 \
	libfreetype6-dev \
	libgeos-dev \
	libpng-dev \
	libspatialindex-dev \
	qt5-style-plugins \
	python3-dev \
	python3-gdal \
	python3-pip \
	python3-pyqt5 \
	python3-pyqt5.qtopengl \
	python3-simplejson \
	python3-tk \
    # Display deps
    libx11-xcb1 \
	libxtst6 \
	libasound2 \
	x11-apps \
	xvfb \
	xauth \ 
    xterm

RUN git clone https://github.com/AntumArk/Flatcam . -b old_flatcam_pyqt5
# Make setup executable
RUN chmod +x setup_ubuntu.sh
RUN ./setup_ubuntu.sh
# Change user so you could run GUI
USER project
