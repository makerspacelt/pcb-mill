FROM ubuntu:latest
WORKDIR /usr/src/app
## for apt to be noninteractive
ENV DEBIAN_FRONTEND noninteractive
ENV DEBCONF_NONINTERACTIVE_SEEN true

## preesed tzdata, update package index, upgrade packages and install needed software
RUN echo "tzdata tzdata/Areas select Europe" > /tmp/preseed.txt; \
    echo "tzdata tzdata/Zones/Europe select Vilnius" >> /tmp/preseed.txt; \
    debconf-set-selections /tmp/preseed.txt && \
    apt-get update && \
    apt-get install -y tzdata

RUN apt-get update && apt-get install -y --no-install-recommends \
    git \
    python3-pip\
    sudo\
    python3-setuptools\
    nano\
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
	python3-tk

COPY Flatcam .
#RUN git clone https://bitbucket.org/jpcgt/flatcam/src/Beta/ -b Beta
#WORKDIR Flatcam
# Make setup executable
RUN chmod +x setup_ubuntu.sh
# Run install
#8 - Europe , 58 - Vilnius. For some reason timezone prompts are there... 
#CMD [ "./setup_ubuntu.sh","8","58" ] 
#CMD [./setup_ubuntu.sh]
