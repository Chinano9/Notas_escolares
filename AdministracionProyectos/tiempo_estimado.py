
O= int(input("duracion optimista"))
M= int(input("duracion probable"))
P= int(input("duracion pesimista"))


TE = (O + (4*M) + P)/6
print("Tiempo esperado", TE)
