parcelas = [
    {"id": "A", "area_ha": 2.0, "N_suelo": 85},
    {"id": "B", "area_ha": 1.4, "N_suelo": 122},
    {"id": "C", "area_ha": 0.9, "N_suelo": 95},
    {"id": "D", "area_ha": 1.2, "N_suelo": 130},
    {"id": "E", "area_ha": 1.8, "N_suelo": 70},
    {"id": "F", "area_ha": 1.0, "N_suelo": 110},
    {"id": "G", "area_ha": 2.5, "N_suelo": 92},
    {"id": "H", "area_ha": 0.7, "N_suelo": 60},
    {"id": "I", "area_ha": 1.6, "N_suelo": 118},
    {"id": "J", "area_ha": 1.1, "N_suelo": 88},
]

# Constantes
N_OBJ = 120  # kg/ha
FRACCION_N = 0.46
DISPON = 0.80

# 1. filter: seleccionar las parcelas deficitarias (N_suelo < N_OBJ)
deficit_parcelas = list(filter(lambda parcela: parcela["N_suelo"] < N_OBJ and parcela["area_ha"] > 0, parcelas))

# 2. map: calcular kg de fertilizante por parcela (kg_producto)
def calculate_fertilizer(parcela):
    deficit_N_ha = max(0, N_OBJ - parcela["N_suelo"])
    kgN_total = deficit_N_ha * parcela["area_ha"]
    # Esto de aqui es por si acaso, aunque es improbable que la division entre cero ocurra
    if (FRACCION_N * DISPON) == 0:
      return {"id": parcela["id"], "kg_producto": 0}
    kg_producto = kgN_total / (FRACCION_N * DISPON)
    return {"id": parcela["id"], "kg_producto": kg_producto}

parcelas_con_fertilizante = list(map(calculate_fertilizer, deficit_parcelas))

# 3. reduce/sum: obtener el total de kg de producto para toda la finca
total_fertilizante = sum(parcela["kg_producto"] for parcela in parcelas_con_fertilizante)


print("Lista de parcelas deficitarias con id y kg_producto:")
for parcela in parcelas_con_fertilizante:
    print(f"  ID: {parcela['id']}, kg_producto: {parcela['kg_producto']:.2f}")

print(f"\nTotal de fertilizante en kg: {total_fertilizante:.2f}")

# Explicación de supuestos
print("\nSupuestos:")
print("- Objetivo de Nitrógeno (N_OBJ) en el suelo es de 120 kg/ha.")
print("- Se utiliza un fertilizante con un 46% de Nitrógeno (FRACCION_N).")
print("- La disponibilidad efectiva del nitrógeno del fertilizante es del 80% (DISPON), considerando pérdidas y eficiencia.")
