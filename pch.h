// pch.h: Dies ist eine vorkompilierte Headerdatei.
// pch.h: To jest prekompilowany plik nagłówkowy.

// Die unten aufgeführten Dateien werden nur einmal kompiliert, um die Buildleistung für zukünftige Builds zu verbessern.
// Wymienione poniżej pliki są kompilowane tylko raz, aby poprawić wydajność kompilacji dla przyszłych kompilacji.

// Dies wirkt sich auch auf die IntelliSense-Leistung aus, Codevervollständigung und viele Features zum Durchsuchen von Code eingeschlossen.
// Wpływa to również na wydajność IntelliSense, w tym uzupełnianie kodu i wiele funkcji przeglądania kodu.

// Die hier aufgeführten Dateien werden jedoch ALLE neu kompiliert, wenn mindestens eine davon zwischen den Builds aktualisiert wird.
// Jednak wymienione tutaj pliki zostaną WSZYSTKIE ponownie skompilowane, jeśli przynajmniej jeden z nich zostanie zaktualizowany między kompilacjami.

// Fügen Sie hier keine Dateien hinzu, die häufig aktualisiert werden sollen, da sich so der Leistungsvorteil ins Gegenteil verkehrt.
// Nie dodawaj tutaj plików, które powinny być często aktualizowane, ponieważ spowoduje to odwrócenie korzyści związanych z wydajnością.


#ifndef PCH_H
#define PCH_H

// Fügen Sie hier Header hinzu, die vorkompiliert werden sollen.
// Dodaj tutaj nagłówki do prekompilacji.

	#include "Client.h"
	#include "UnVerify.h"
	#include "Admin.h"
	#include "Employee.h"

	#include "Category.h"
	#include "Company.h"
	#include "Offer.h"
	#include "Product.h"
	#include "Transaction.h"
	#include "User.h"

	#include <msclr/marshal_cppstd.h>
	#include <string>
	#include <time.h>

#endif PCH_H