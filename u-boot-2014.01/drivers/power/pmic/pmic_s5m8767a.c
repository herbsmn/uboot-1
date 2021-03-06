/*
 *  Copyright (C) 2014 Emdoor Electronics
 *  jingfeng.shi <jingfeng.shi@emdoor.com>
 *  Based on pmic_max8998.c
 * SPDX-License-Identifier:	GPL-2.0+
 */

#include <common.h>
#include <power/pmic.h>
#include <power/s5m8767a_pmic.h>
#include <errno.h>

int pmic_init(unsigned char bus)
{
	static const char name[] = CONFIG_PMIC_NAME;
	struct pmic *p = pmic_alloc();

	if (!p) {
		printf("%s: POWER allocation error!\n", __func__);
		return -ENOMEM;
	}

	printf("Board PMIC:%s init\n", name);

	p->name = name;
	p->interface = PMIC_I2C;
	p->number_of_regs = PMIC_NUM_OF_REGS;
	p->hw.i2c.addr = S5M8767A_I2C_ADDR;
	p->hw.i2c.tx_num = 1;
	p->bus = bus;

	return 0;
}
