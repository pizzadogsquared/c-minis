//code by Elijah Sprouse

//header file
#include "vending_lib.h"

//global constant
const char* prodDesc[ProductType ptype = NUM_PRODUCTS] = 
{
	
}
	
	
	
typedef enum
{
	CHOCOLATE_BAR,
	PEPSI,
	CHIPS,
	CHEWING_GUM,
	PHONE_CASE,
	CHAPSTICK,
	NUM_PRODUCTS
}
ProductType;



typedef enum
{
	cancel = -1,
	checkout = 0,
	continue = 1
}
Menu;



typedef enum
{
	cash,
	credit,
	contactless
}
Payment;



typedef enum
{
	MasterCard,
	Visa,
	Discover,
	American Express
}
CreditCard;



typedef enum
{
	Google Wallet,
	Apple Pay
}
Contactless;



typedef struct product
{
	int CHOCOLATE_BAR, PEPSI, CHIPS, CHEWING_GUM, PHONE_CASE, CHAPSTICK;
}
Product;



typedef struct cartitem
{
	char product;
	int quantity;
}
CartItem;



typedef struct shoppingcart
{
	char* inCart[MAX_NUM_PRODUCTS];
	int total;
}
ShoppingCart;








