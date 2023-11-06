/******************************************************************************************************************** 
*                                  Author: Abdelrahman Gamal Abdelwanies Mohamed                                    *
*			                       Created: 6/11/2023                                                               *
*			                       File: DIO_Interface.h                                                            *
*			                       [DIO Module Driver]                                                              *
********************************************************************************************************************/

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/* Macros For DIO PORTs */
#define DIO_PORTA     0
#define DIO_PORTB     1
#define DIO_PORTC     2
#define DIO_PORTD     3


/* Macros For DIO PINs */
#define DIO_PIN0      0
#define DIO_PIN1      1
#define DIO_PIN2      2
#define DIO_PIN3      3
#define DIO_PIN4      4
#define DIO_PIN5      5
#define DIO_PIN6      6 
#define DIO_PIN7      7

/* Macros For DIO PINs Directions */
#define DIO_INPUT     0
#define DIO_OUTPUT    1

/* Macros For DIO PORTs Directions */
#define PORT_INPUT     0x00
#define PORT_OUTPUT    0xff


/* Macros For DIO Value */
#define LOW           0
#define HIGH          1

/* Macros For DIO Value */
#define PORT_LOW      0x00
#define PORT_HIGH     0xff



Error_State DIO_SetPinDirection  (u8 Copy_u8PORT,u8 Copy_u8PIN,u8 Copy_u8Direction);
Error_State DIO_SetPinValue      (u8 Copy_u8PORT,u8 Copy_u8PIN,u8 Copy_u8Value);
Error_State DIO_TogglePinValue   (u8 Copy_u8PORT,u8 Copy_u8PIN);
Error_State DIO_u8ScanPinValue   (u8 Copy_u8PORT,u8 Copy_u8PIN,u8 *Copy_u8PtrData);

Error_State DIO_SetPortDirection (u8 Copy_u8PORT,u8 Copy_u8Direction);
Error_State DIO_SetPortValue     (u8 Copy_u8PORT,u8 Copy_u8Value);
Error_State DIO_TogglePortValue  (u8 Copy_u8PORT);
Error_State DIO_u8ScanPortValue  (u8 Copy_u8PORT,u8 *Copy_u8PtrData);



#endif /* DIO_INTERFACE_H_ */
