from sklearn.ensemble import RandomForestRegressor
from sklearn.preprocessing import OneHotEncoder
from sklearn.pipeline import make_pipeline
from sklearn.compose import ColumnTransformer
from sklearn.model_selection import train_test_split
from sklearn.metrics import mean_absolute_error
import pandas as pd
import numpy as np
import sys

# Charger les données
df = pd.read_csv("chantiers_dataset.csv")

# Features et target
X = df[["budget", "progression", "statut"]]
y = df["jours_restants"]

# Preprocessing : encodage du statut
preprocessor = ColumnTransformer(transformers=[
    ("statut_enc", OneHotEncoder(), ["statut"])
], remainder="passthrough")

# Pipeline avec RandomForest
model = make_pipeline(preprocessor, RandomForestRegressor(n_estimators=100, random_state=42))
model.fit(X, y)

# Si exécuté avec arguments, faire une prédiction
if len(sys.argv) == 4:
    try:
        budget = float(sys.argv[1])
        progression = int(sys.argv[2])
        statut = sys.argv[3]

        input_data = pd.DataFrame([{
            "budget": budget,
            "progression": progression,
            "statut": statut
        }])

        prediction = model.predict(input_data)[0]

        # Simuler un niveau de confiance simple (basé sur l'erreur moyenne)
        X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)
        y_pred = model.predict(X_test)
        mae = mean_absolute_error(y_test, y_pred)
        confiance = max(0, 1 - mae / y.mean())  # Échelle de confiance entre 0 et 1

        print(f"{int(round(prediction))}|{round(confiance, 2)}")
    except Exception as e:
        print(f"Erreur: {e}", file=sys.stderr)
else:
    print("Usage: python predict_duration.py <budget> <progression> <statut>", file=sys.stderr)
