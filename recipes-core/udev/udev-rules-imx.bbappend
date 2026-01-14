FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

SRC_URI += " \
	 file://localextra.rules \
"
do_install:append() {
        install -d ${D}${sysconfdir}/udev/rules.d
        install -m 0644 ${WORKDIR}/localextra.rules ${D}${sysconfdir}/udev/rules.d/
}

