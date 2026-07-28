/* SPDX-License-Identifier: MIT */
/******************************************************************************
 * physdev.h
 *
 * Copyright (c) 2006, Keir Fraser
 */

#ifndef __XEN_PUBLIC_PHYSDEV_H__
#define __XEN_PUBLIC_PHYSDEV_H__

#include "xen.h"

/*
 * Prototype for this hypercall is:
 *  int physdev_op(int cmd, void *args)
 * @cmd  == PHYSDEVOP_??? (physdev operation).
 * @args == Operation-specific extra arguments (NULL if none).
 */

#define XEN_PCI_DEV_EXTFN		0x1
#define XEN_PCI_DEV_VIRTFN		0x2
#define XEN_PCI_DEV_PXM			0x4

/*
 * Notify Xen that a new PCI device is present on the system, so that it
 * can be tracked by the hypervisor. Only meaningful when issued by the
 * hardware domain.
 */
#define PHYSDEVOP_pci_device_add	25
struct physdev_pci_device_add {
	/* IN */
	uint16_t seg;
	uint8_t bus;
	uint8_t devfn;
	uint32_t flags;
	struct {
		uint8_t bus;
		uint8_t devfn;
	} physfn;
	/*
	 * Optional parameters array.
	 * First element ([0]) is PXM domain associated with the device (if
	 * XEN_PCI_DEV_PXM is set)
	 */
	uint32_t optarr[XEN_FLEX_ARRAY_DIM];
};
typedef struct physdev_pci_device_add physdev_pci_device_add_t;
DEFINE_XEN_GUEST_HANDLE(physdev_pci_device_add_t);

/*
 * Notify Xen that a PCI device is no longer present on the system. Only
 * meaningful when issued by the hardware domain.
 */
#define PHYSDEVOP_pci_device_remove	26

struct physdev_pci_device {
	/* IN */
	uint16_t seg;
	uint8_t bus;
	uint8_t devfn;
};
typedef struct physdev_pci_device physdev_pci_device_t;
DEFINE_XEN_GUEST_HANDLE(physdev_pci_device_t);

/*
 * Notify the hypervisor that a PCI device has been reset, so that any
 * internally cached state is regenerated. Should be called after any
 * device reset performed by the hardware domain.
 */
#define PHYSDEVOP_pci_device_reset	32

struct pci_device_reset {
	physdev_pci_device_t dev;
#define PCI_DEVICE_RESET_COLD	0x0
#define PCI_DEVICE_RESET_WARM	0x1
#define PCI_DEVICE_RESET_HOT	0x2
#define PCI_DEVICE_RESET_FLR	0x3
#define PCI_DEVICE_RESET_MASK	0x3
	uint32_t flags;
};
typedef struct pci_device_reset pci_device_reset_t;
DEFINE_XEN_GUEST_HANDLE(pci_device_reset_t);

#endif /* __XEN_PUBLIC_PHYSDEV_H__ */

/*
 * Local variables:
 * mode: C
 * c-file-style: "BSD"
 * c-basic-offset: 4
 * tab-width: 4
 * indent-tabs-mode: nil
 * End:
 */
