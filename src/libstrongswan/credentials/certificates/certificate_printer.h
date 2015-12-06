/*
 * Copyright (C) 2015 Andreas Steffen
 * HSR Hochschule fuer Technik Rapperswil
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.  See <http://www.fsf.org/copyleft/gpl.txt>.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 */

/**
 * @defgroup certificate_printer certificate_printer
 * @{ @ingroup certificates
 */

#ifndef CERTIFICATE_PRINTER_H_
#define CERTIFICATE_PRINTER_H_

typedef struct certificate_printer_t certificate_printer_t;

#include "credentials/certificates/certificate.h"

#include <stdio.h>

/**
 * An object for printing certificate information.
 */
struct certificate_printer_t {

	/**
	 * Print a certificate.
	 *
	 * @cert			certificate to be printed
	 * @has_privkey		indicates that certificate has a matching private key
	 */
	void (*print)(certificate_printer_t *this, certificate_t *cert,
				  bool has_privkey);

	/**
	 * Destroy the certificate_printer object.
	 */
	void (*destroy)(certificate_printer_t *this);
};

/**
 * Create a certificate_printer object
 *
 * @param f				file where print output is directed to (usually stdout)
 * @param detailed		print more detailed certificate information
 * @param utc			print time inforamtion in UTC
 */
certificate_printer_t* certificate_printer_create(FILE *f, bool detailed,
														   bool utc);

#endif /** CERTIFICATE_PRINTER_H_ @}*/
