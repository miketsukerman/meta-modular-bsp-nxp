FILESEXTRAPATHS:prepend := "${THISDIR}/files:"

SRC_URI:append:aom5521a1-db2510 = " \
        file://0001-Restore-i.MX95-A0-A1-Rev-A-silicon-support.patch \
        file://0002-Add-AOM5521-A0-A1-revision.patch \ 
"
#         file://0001-Mask-FCCU-fault-68-DDRMIX-SSI-parity-on-i.MX95.patch \
#         file://0002-Temporarily-mask-FCCU-fault-66-NOC-SSI-parity-on-i.M.patch \
# "
