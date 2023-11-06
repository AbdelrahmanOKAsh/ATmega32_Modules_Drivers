/******************************************************************************************************************** 
*                                  Author: Abdelrahman Gamal Abdelwanies Mohamed                                    *
*			                       Created: 6/11/2023                                                               *
*			                       File: DIO_Program.c                                                              *
*			                       [DIO Module Driver]                                                              *
********************************************************************************************************************/

#include "../../../../LIBs/STD_TYPES.h"
#include "../../../../LIBs/BIT_MATH.h"
#include "DIO_Private.h"
#include "DIO_Interface.h"


Error_State DIO_SetPinDirection (u8 Copy_u8PORT,u8 Copy_u8PIN,u8 Copy_u8Direction)
{
    Error_State Local_ErrorState=VALID;

    if ((Copy_u8PORT<=DIO_PORTD) && (Copy_u8PIN<=DIO_PIN7))
    {
        if (Copy_u8Direction == DIO_INPUT)
        {
            switch (Copy_u8PORT)
            {
                case DIO_PORTA:
                    CLEAR_BIT(DDRA,Copy_u8PIN);
                    break;

                case DIO_PORTB:
                    CLEAR_BIT(DDRB,Copy_u8PIN);
                    break;

                case DIO_PORTC:
                    CLEAR_BIT(DDRC,Copy_u8PIN);
                    break;

                case DIO_PORTD:
                    CLEAR_BIT(DDRD,Copy_u8PIN);
                    break;

                default:
                    Local_ErrorState=NOT_VALID;
                    break;
            }
        }

        else if (Copy_u8Direction == DIO_OUTPUT)
        {
            switch (Copy_u8PORT)
            {
                case DIO_PORTA:
                    SET_BIT(DDRA,Copy_u8PIN);
                    break;

                case DIO_PORTB:
                    SET_BIT(DDRB,Copy_u8PIN);
                    break;

                case DIO_PORTC:
                    SET_BIT(DDRC,Copy_u8PIN);
                    break;

                case DIO_PORTD:
                    SET_BIT(DDRD,Copy_u8PIN);
                    break;

                default:
                    Local_ErrorState=NOT_VALID;
                    break;
            }
        }

        else
        {
            Local_ErrorState=NOT_VALID;
        }
    }

    else
    {
        Local_ErrorState=NOT_VALID;
    }

    return Local_ErrorState;
}


Error_State DIO_SetPinValue (u8 Copy_u8PORT,u8 Copy_u8PIN,u8 Copy_u8Value)
{
    Error_State Local_ErrorState=VALID;

    if ((Copy_u8PORT<=DIO_PORTD) && (Copy_u8PIN<=DIO_PIN7))
    {
        if (Copy_u8Value == LOW)
        {
            switch (Copy_u8PORT)
            {
                case DIO_PORTA:
                    CLEAR_BIT(PORTA,Copy_u8PIN);
                    break;

                case DIO_PORTB:
                    CLEAR_BIT(PORTB,Copy_u8PIN);
                    break; 

                case DIO_PORTC:
                    CLEAR_BIT(PORTC,Copy_u8PIN);
                    break; 

                case DIO_PORTD:
                    CLEAR_BIT(PORTD,Copy_u8PIN);
                    break;

                default:
                    Local_ErrorState=NOT_VALID;
                    break;  
            }
        }

        else if (Copy_u8Value == HIGH)
        {
            switch (Copy_u8PORT)
            {
                case DIO_PORTA:
                    SET_BIT(PORTA,Copy_u8PIN);
                    break;

                case DIO_PORTB:
                    SET_BIT(PORTB,Copy_u8PIN);
                    break; 

                case DIO_PORTC:
                    SET_BIT(PORTC,Copy_u8PIN);
                    break; 

                case DIO_PORTD:
                    SET_BIT(PORTD,Copy_u8PIN);
                    break;

                default:
                    Local_ErrorState=NOT_VALID;
                    break;  
            }
        }

        else
        {
            Local_ErrorState=NOT_VALID;
        }
    }

    else
    {
        Local_ErrorState=NOT_VALID;
    }

    return Local_ErrorState;
}


Error_State DIO_TogglePinValue (u8 Copy_u8PORT,u8 Copy_u8PIN)
{
    Error_State Local_ErrorState=VALID;
    if((Copy_u8PORT<=DIO_PORTD) && (Copy_u8PIN<=DIO_PIN7))
    {
        switch (Copy_u8PORT)
        {
            case DIO_PORTA:
                TOGGLE_BIT(PORTA,Copy_u8PIN);
                break;

            case DIO_PORTB:
                TOGGLE_BIT(PORTB,Copy_u8PIN);
                break;

            case DIO_PORTC:
                TOGGLE_BIT(PORTC,Copy_u8PIN);
                break;

            case DIO_PORTD:
                TOGGLE_BIT(PORTD,Copy_u8PIN);
                break;

            default:
                Local_ErrorState=NOT_VALID;
                break;  
        }
    }

    else
    {
        Local_ErrorState=NOT_VALID;
    }

    return Local_ErrorState;    
}


Error_State DIO_u8ScanPinValue (u8 Copy_u8PORT,u8 Copy_u8PIN,u8 *Copy_u8PtrData)
{
    Error_State Local_ErrorState=VALID;

    if((Copy_u8PORT<=DIO_PORTD) && (Copy_u8PIN<=DIO_PIN7))
    {
        switch (Copy_u8PORT)
        {
            case DIO_PORTA:
                *Copy_u8PtrData=SCAN_BIT(PINA,Copy_u8PIN);
                break;

            case DIO_PORTB:
                *Copy_u8PtrData=SCAN_BIT(PINB,Copy_u8PIN);
                break;

            case DIO_PORTC:
                *Copy_u8PtrData=SCAN_BIT(PINC,Copy_u8PIN);
                break;

            case DIO_PORTD:
                *Copy_u8PtrData=SCAN_BIT(PIND,Copy_u8PIN);
                break;

            default:
                Local_ErrorState=NOT_VALID;
                break;  
        }

    }

    else
    {
        Local_ErrorState=NOT_VALID;
    }
        
    return Local_ErrorState;
}

Error_State DIO_SetPortDirection (u8 Copy_u8PORT,u8 Copy_u8Direction)
{
    Error_State Local_ErrorState=VALID;

    if(Copy_u8PORT<=DIO_PORTD)
    {
        if (Copy_u8Direction == DIO_INPUT)
        {
            switch (Copy_u8PORT)
            {
                case DIO_PORTA:
                    DDRA=PORT_INPUT;
                    break;

                case DIO_PORTB:
                    DDRB=PORT_INPUT;
                    break;

                case DIO_PORTC:
                    DDRC=PORT_INPUT;
                    break;

                case DIO_PORTD:
                    DDRD=PORT_INPUT;
                    break;

                default:
                    Local_ErrorState=NOT_VALID;
                    break;  
            }
        }

        else if (Copy_u8Direction == DIO_OUTPUT)
        {
            switch (Copy_u8PORT)
            {
                case DIO_PORTA:
                    DDRA=PORT_OUTPUT;
                    break;

                case DIO_PORTB:
                    DDRB=PORT_OUTPUT;
                    break;

                case DIO_PORTC:
                    DDRC=PORT_OUTPUT;
                    break;

                case DIO_PORTD:
                    DDRD=PORT_OUTPUT;
                    break;

                default:
                    Local_ErrorState=NOT_VALID;
                    break;  
            }
        }

        else
        {
            Local_ErrorState=NOT_VALID;
        }
    }

    else
    {
        Local_ErrorState=NOT_VALID;
    }
        
    return Local_ErrorState;
    
}


Error_State DIO_SetPortValue (u8 Copy_u8PORT,u8 Copy_u8Value)
{
    Error_State Local_ErrorState=VALID;
    
    if((Copy_u8PORT<=DIO_PORTD) && (Copy_u8Value<=PORT_HIGH))
    {
        switch (Copy_u8PORT)
        {
            case DIO_PORTA:
                PORTA=Copy_u8Value;
                break;

            case DIO_PORTB:
                PORTB=Copy_u8Value;
                break;

            case DIO_PORTC:
                PORTC=Copy_u8Value;
                break;

            case DIO_PORTD:
                PORTD=Copy_u8Value;
                break;

            default:
                Local_ErrorState=NOT_VALID;
                break;  
        }
    }

    else
    {
        Local_ErrorState=NOT_VALID;
    }
        
    return Local_ErrorState;
}


Error_State DIO_TogglePortValue (u8 Copy_u8PORT)
{
    Error_State Local_ErrorState=VALID;
    
    if(Copy_u8PORT<=DIO_PORTD)
    {
        switch (Copy_u8PORT)
        {
            case DIO_PORTA:
                PORTA=~(PORTA);
                break;

            case DIO_PORTB:
                PORTB=~(PORTB);
                break;

            case DIO_PORTC:
                PORTC=~(PORTC);
                break;

            case DIO_PORTD:
                PORTD=~(PORTD);
                break;

            default:
                Local_ErrorState=NOT_VALID;
                break;  
        }
    }

    else
    {
        Local_ErrorState=NOT_VALID;
    }
        
    return Local_ErrorState;    
}

Error_State DIO_u8ScanPortValue (u8 Copy_u8PORT,u8 *Copy_u8PtrData)
{
     Error_State Local_ErrorState=VALID;

    if (Copy_u8PORT<=DIO_PORTD)
    {
        switch (Copy_u8PORT)
        {
            case DIO_PORTA:
                *Copy_u8PtrData=PINA;
                break;

            case DIO_PORTB:
                *Copy_u8PtrData=PINB;
                break;
                
            case DIO_PORTC:
                *Copy_u8PtrData=PINC;
                break;

            case DIO_PORTD:
                *Copy_u8PtrData=PIND;
                break;

            default:
                Local_ErrorState=NOT_VALID;
                break;  
        }
    }

    else
    {
        Local_ErrorState=NOT_VALID;
    }
        
    return Local_ErrorState;
}