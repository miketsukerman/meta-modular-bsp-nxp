FILESEXTRAPATHS:prepend := "${THISDIR}/${PN}:"

SRC_URI += " \
	file://modules-blacklist.conf \
"

DISTRO_FEATURES:remove = "sysvinit"
IMAGE_INSTALL:append = " cmake ninja gcc-arm-none-eabi"
IMAGE_INSTALL:append = " libgpiod libgpio-dev libgpiod-tools"
IMAGE_INSTALL:append = " firmware-imx-sdma-imx7d"
IMAGE_INSTALL:append = " wireless-regdb-static"
IMAGE_INSTALL:append = " lmsensors"
IMAGE_INSTALL:append = " linux-firmware-rtl-nic"
#IMAGE_INSTALL:append = " linux-firmware-rtl8168-nic"
# rtl-nic for r8169

IMAGE_INSTALL:append = " udev-rules-imx"
NETMAN_PACKAGES = "\
       networkmanager \
       networkmanager-nmcli \
"
# Logic to decide if we include NetworkManager
PREFERRED_CONNECTIVITY_MANAGER = "${@bb.utils.contains('DISTRO_FEATURES', 'wayland', 'networkmanager', '', d)}"

RDEPENDS:${PN}:append = " \
    gptfdisk \
    hostapd \
    hdparm \
    imx-kobs \
    iw \
    kmod \
    packagegroup-tools-bluetooth \
    bluealsa \
    pm-utils \
    rng-tools \
    wpa-supplicant \
    wireless-regdb-static \
    u-boot-fw-utils \
    u-boot-default-env \
    ${@bb.utils.contains('PREFERRED_CONNECTIVITY_MANAGER', 'networkmanager', '${NETMAN_PACKAGES}', '', d)} \
"
do_install:append() {
	install -m 0755 -d ${D}${sysconfdir}/modprobe.d
	install -m 0644 ${WORKDIR}/modules-blacklist.conf ${D}${sysconfdir}/modprobe.d
}

