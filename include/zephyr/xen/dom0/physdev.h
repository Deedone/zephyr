/*
 * Copyright (c) 2026 EPAM Systems
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file
 * @brief Xen Dom0 PCI physdev operations.
 * @ingroup xen_dom0_physdev
 */

#ifndef __XEN_DOM0_PHYSDEV_H__
#define __XEN_DOM0_PHYSDEV_H__

#include <zephyr/xen/public/physdev.h>
#include <zephyr/xen/public/xen.h>

/**
 * @defgroup xen_dom0_physdev Xen Dom0 physdev
 * @ingroup xen_dom0
 * @brief Notify Xen about physical PCI devices owned by the hardware domain.
 * @{
 */

/**
 * @brief Notify Xen that a PCI device is present on the system.
 *
 * @kconfig_dep{CONFIG_XEN_DOM0}
 *
 * @param seg PCI segment of the device.
 * @param bus PCI bus number of the device.
 * @param devfn PCI device/function number of the device.
 * @param flags Combination of XEN_PCI_DEV_* flags describing the device.
 *
 * @return 0 on success, negative errno value on failure.
 */
int xen_physdev_pci_device_add(uint16_t seg, uint8_t bus, uint8_t devfn, uint32_t flags);

/**
 * @brief Notify Xen that a PCI device is no longer present on the system.
 *
 * @kconfig_dep{CONFIG_XEN_DOM0}
 *
 * @param seg PCI segment of the device.
 * @param bus PCI bus number of the device.
 * @param devfn PCI device/function number of the device.
 *
 * @return 0 on success, negative errno value on failure.
 */
int xen_physdev_pci_device_remove(uint16_t seg, uint8_t bus, uint8_t devfn);

/**
 * @brief Notify Xen that a PCI device has just been reset by the hardware
 * domain, so that any state Xen caches for it gets regenerated.
 *
 * @kconfig_dep{CONFIG_XEN_DOM0}
 *
 * @param seg PCI segment of the device.
 * @param bus PCI bus number of the device.
 * @param devfn PCI device/function number of the device.
 * @param flags One of PCI_DEVICE_RESET_COLD/WARM/HOT/FLR.
 *
 * @return 0 on success, negative errno value on failure.
 */
int xen_physdev_pci_device_reset(uint16_t seg, uint8_t bus, uint8_t devfn, uint32_t flags);

/** @} */

#endif /* __XEN_DOM0_PHYSDEV_H__ */
