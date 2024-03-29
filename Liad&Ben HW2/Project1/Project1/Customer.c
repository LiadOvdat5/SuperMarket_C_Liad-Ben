#define _CRT_SECURE_NO_WARNINGS
#include "Customer.h"
#include "GeneralFunc.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int initCustomer(Customer* customer)
{
	/*
	initCustomer

	input: Customer
	output: 0 if failed creating, 1 if created cutomer
	*/
	
	char* pName = createDynStr("customer's name");
	if (!pName)
		return 0;

	customer->name = pName;
	
	customer->cart = NULL; //customer hasnt started purchase yet, so there is no cart now.
	customer->balance = 0;
	return 1;
}
void printCustomer(const Customer* customer)
{
	printf("customer's name: %s | customer's balance: %.2f, ", customer->name,customer->balance);

	if (customer->cart)
	{
		printShoppingCart(customer->cart);
	}
	else
		printf("Cart has'nt been created yet\n");
}
void freeCustomer(Customer* customer)
{
	/*
	freeCustomer

	input: Customer
	output: free the space of shopping cart (which free the items in it) and name
	*/

	if(customer->cart )
		freeShoppingCart(customer->cart);

	free(customer->name);
}
int initEmptyCart(Customer* customer)
{
	ShoppingCart* pShopCart = (ShoppingCart*)malloc(sizeof(ShoppingCart));
	if (!pShopCart)
		return 0;

	customer->cart = pShopCart;
	initShoppingCart(customer->cart);
	return 1;
}

