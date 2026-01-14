FILESEXTRAPATHS:prepend := "${THISDIR}/${BPN}:"

PACKAGECONFIG:append = " networkd resolved"
SRC_URI += " \
	file://imx.conf \
"

do_install:append() {
    install -Dm 0644 ${WORKDIR}/imx.conf ${D}${sysconfdir}/systemd/logind.conf.d/imx.conf
}

