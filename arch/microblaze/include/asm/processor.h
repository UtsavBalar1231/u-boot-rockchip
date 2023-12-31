/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Copyright (C) 2011 Michal Simek <monstr@monstr.eu>
 */

#ifndef __ASM_MICROBLAZE_PROCESSOR_H
#define __ASM_MICROBLAZE_PROCESSOR_H

/* Microblaze board initialization function */
void board_init(void);

/* Watchdog functions */
extern void hw_watchdog_disable(void);

#endif /* __ASM_MICROBLAZE_PROCESSOR_H */
