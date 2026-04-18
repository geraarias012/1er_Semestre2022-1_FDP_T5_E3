#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int boleta;
    char nombre_alumno[50];
    int edad;
    char sexo[2];
    char direccion[50];
    char telefono[11];
    char correo[50];
} datos_alumnos;

void registrar_alumno(void);
void consultar_datos(void);
void modificar_datos(void);
void baja_datos(void);

int main()
{
    char op;
    do{
    cabecera();
    printf("\nSELECCIONE UNA DE LAS SIGUIENTES OPCIONES:\n");
    printf("A] DAR DE ALTA UN ALUMNO\n");
    printf("B] CONSULTAR DATOS ALMACENADOS\n");
    printf("C] MODIFICAR DATOS\n");
    printf("D] BAJA DE REGISTROS\n");
    printf("E] SALIR\n");
    printf("\nINTRODUZCA UNA OPCION : ");
    scanf("%s", &op);

    switch(op)
        {
            case 'a':
            case 'A':
                {
                registrar_alumno();
                break;
                }
            case 'b':
            case 'B':
                {
                consultar_datos();
                system("PAUSE");
                break;
                }
            case 'c':
            case 'C':
                {
                modificar_datos();
                system("PAUSE");
                break;
                }
            case 'd':
            case 'D':
                {
                baja_datos();
                system("PAUSE");
                break;
                }
            case 'e':
            case 'E':
                break;
            default:
                {
            printf("\nOpcion no valida\n\n");
            system("PAUSE");
            break;
                }
        }
            system("CLS");
        }while(op!='e'&&op!='E');
        printf("\nFINAL DEL PROGRAMA\n");
    return 0;
}

void registrar_alumno(void)
{
    datos_alumnos directorio;
    FILE *alias;
    int boleta,dir_fisica;
    printf("\nDAR DE ALTA UN ALUMNO\n");
    alias=fopen("DATOS.DAT","rb+");
    if(alias==NULL)
       {
           alias=fopen("DATOS.DAT", "wb+");
       }
       printf("\nINGRESE EL NUMERO DE BOLETA: ");
       scanf("%i", &boleta);
       dir_fisica=boleta*sizeof(directorio);
       fseek(alias,dir_fisica,SEEK_SET);
       fread(&directorio,sizeof(directorio),1,alias);
       if(directorio.boleta==boleta)
        {
            printf("\nREGISTRO DUPLICADO\n\n");
            fclose(alias);
            system("PAUSE");
            return;
        }
        printf("NOMBRE DEL ALUMNO: ");
        fflush(stdin);
        gets(directorio.nombre_alumno);
        printf("EDAD: ");
        scanf("%i", &directorio.edad);
        printf("SEXO(M/F): ");
        fflush(stdin);
        gets(directorio.sexo);
        printf("DIRECCION: ");
        fflush(stdin);
        gets(directorio.direccion);
        printf("TELEFONO: ");
        fflush(stdin);
        gets(directorio.telefono);
        printf("CORREO ELECTRONICO: ");
        fflush(stdin);
        gets(directorio.correo);
        directorio.boleta=boleta;
        fseek(alias,dir_fisica,SEEK_SET);
        fwrite(&directorio, sizeof(directorio), 1, alias);
        fclose(alias);
        printf("\nALUMNO GUARDADO\n\n");
        system("PAUSE");
}
void consultar_datos(void)
{
    datos_alumnos directorio;
    FILE *alias;
    int boleta,dir_fisica;
    printf("\nCONSULTAR DATOS ALMACENADOS\n");
    alias=fopen("DATOS.DAT","rb");
    if(alias==NULL)
       {
           printf("\nNO EXISTE EL ARCHIVO\n\n");
           return;
       }
       printf("\nINGRESE EL NUMERO DE BOLETA: ");
       scanf("%i", &boleta);
       dir_fisica=boleta*sizeof(directorio);
       fseek(alias,dir_fisica,SEEK_SET);
       fread(&directorio,sizeof(directorio),1,alias);
       if(directorio.boleta==boleta)
        {
        printf("\nNOMBRE DEL ALUMNO: %s\n", directorio.nombre_alumno);
        printf("EDAD: %i\n", directorio.edad);
        printf("SEXO: %s\n", directorio.sexo);
        printf("DIRECCION: %s\n", directorio.direccion);
        printf("TELEFONO: %s\n", directorio.telefono);
        printf("CORREO ELECTRONICO: %s\n\n", directorio.correo);
        return;
        }
        else
        {
            printf("\nNO EXISTE EL REGISTRO\n\n");
            return;
        }
    fclose(alias);
}
void modificar_datos(void)
{
    datos_alumnos directorio;
    FILE *alias;
    int boleta,dir_fisica;
    printf("\nMODIFICAR DATOS\n");
    alias=fopen("DATOS.DAT","rb+");
    if(alias==NULL)
       {
           printf("\nNO EXISTE EL ARCHIVO\n\n");
           return;
       }
       printf("\nINGRESE EL NUMERO DE BOLETA: ");
       scanf("%i", &boleta);
       dir_fisica=boleta*sizeof(directorio);
       fseek(alias,dir_fisica,SEEK_SET);
       fread(&directorio,sizeof(directorio),1,alias);
       if(directorio.boleta==boleta)
        {
        printf("\nNOMBRE DEL ALUMNO: %s\n", directorio.nombre_alumno);
        printf("EDAD: %i\n", directorio.edad);
        printf("SEXO: %s\n", directorio.sexo);
        printf("DIRECCION: %s\n", directorio.direccion);
        printf("TELEFONO: %s\n", directorio.telefono);
        printf("CORREO ELECTRONICO: %s\n", directorio.correo);
        printf("\n\nCAPTURE LOS NUEVOS DATOS:\n");
        printf("NOMBRE DEL ALUMNO: ");
        fflush(stdin);
        gets(directorio.nombre_alumno);
        printf("EDAD: ");
        scanf("%i", &directorio.edad);
        printf("SEXO(M/F): ");
        fflush(stdin);
        gets(directorio.sexo);
        printf("DIRECCION: ");
        fflush(stdin);
        gets(directorio.direccion);
        printf("TELEFONO: ");
        fflush(stdin);
        gets(directorio.telefono);
        printf("CORREO ELECTRONICO: ");
        fflush(stdin);
        gets(directorio.correo);
        fseek(alias,ftell(alias)-sizeof(directorio),SEEK_SET);
        fwrite(&directorio, sizeof(directorio), 1, alias);
        fclose(alias);
        printf("\nMODIFICACION GUARDADA\n\n");
        return;
        }
        else
        {
            printf("\nNO SE ENCUNTRA EL REGISTRO\n\n");
        }
        fclose(alias);
        return;
}
void baja_datos(void)
{
    datos_alumnos directorio;
    FILE *alias;
    int boleta,dir_fisica;
    char op;
    printf("\nBAJA DE REGISTROS\n");
    alias=fopen("DATOS.DAT","rb+");
    if(alias==NULL)
       {
           printf("\nNO EXISTE EL ARCHIVO\n\n");
           return;
       }
       printf("\nINGRESE EL NUMERO DE BOLETA: ");
       scanf("%i", &boleta);
       dir_fisica=boleta*sizeof(directorio);
       fseek(alias,dir_fisica,SEEK_SET);
       fread(&directorio,sizeof(directorio),1,alias);
       if(directorio.boleta==boleta)
        {
        printf("\nNOMBRE DEL ALUMNO: %s\n", directorio.nombre_alumno);
        printf("EDAD: %i\n", directorio.edad);
        printf("SEXO: %s\n", directorio.sexo);
        printf("DIRECCION: %s\n", directorio.direccion);
        printf("TELEFONO: %s\n", directorio.telefono);
        printf("CORREO ELECTRONICO: %s\n", directorio.correo);
        directorio.boleta=0;
        strcpy(directorio.nombre_alumno,"");
        directorio.edad=0;
        strcpy(directorio.sexo,"");
        strcpy(directorio.direccion,"");
        strcpy(directorio.telefono,"");
        strcpy(directorio.correo,"");
        do
        {
            printf("\nESTA SEGURO DE QUE DESEA ELIMINAR ESTE REGISTRO? (SI=S/NO=N): ");
        op=toupper(getche());
        }while(op!='S'&&op!='N');
        if(op=='S')
        {
            fseek(alias,ftell(alias)-sizeof(directorio),SEEK_SET);
            fwrite(&directorio,sizeof(directorio),1,alias);
            printf("\n\nREGISTRO ELIMINADO LOGICAMENTE\n\n");
        }
        else
        {
            printf("\n\nREGISTRO NO ELIMINADO\n\n");
        }
            fclose(alias);
            return;
        }
        else
        {
            printf("\nNO SE ENCUNTRA EL REGISTRO\n\n");
        }
        fclose(alias);
        return;
}
