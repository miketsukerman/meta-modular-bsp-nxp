SRC_URI += " \
	file://rom5721-db5901.dts;subdir=git/arch/arm64/boot/dts/freescale \
	file://rom5721-db5901.dtsi;subdir=git/arch/arm64/boot/dts/freescale \
	file://rom5721-db5901-dsi2dp.dts;subdir=git/arch/arm64/boot/dts/freescale \
	file://rom5721-db5901-dsi2dp-dummy.dts;subdir=git/arch/arm64/boot/dts/freescale \
	file://display-port-sn65dsi86.cfg \
"

do_configure:prepend() {
	echo 'dtb-$(CONFIG_ARCH_MXC) += rom5721-db5901.dtb' >> ${S}/arch/arm64/boot/dts/freescale/Makefile
	echo 'dtb-$(CONFIG_ARCH_MXC) += rom5721-db5901-dsi2dp.dtb' >> ${S}/arch/arm64/boot/dts/freescale/Makefile
	echo 'dtb-$(CONFIG_ARCH_MXC) += rom5721-db5901-dsi2dp-dummy.dtb' >> ${S}/arch/arm64/boot/dts/freescale/Makefile
}

DELTA_KERNEL_DEFCONFIG += "display-port-sn65dsi86.cfg"
