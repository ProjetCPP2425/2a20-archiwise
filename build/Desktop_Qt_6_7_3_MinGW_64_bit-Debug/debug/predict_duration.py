import pandas as pd
import joblib
import sys
from sklearn.metrics import mean_absolute_error

# Charger le modèle entraîné
try:
    model = joblib.load("modele_chantier.joblib")
except Exception as e:
    print(f"Erreur : impossible de charger le modèle - {e}", file=sys.stderr)
    sys.exit(1)

# Charger les données d'origine pour calcul de la confiance
try:
    df = pd.read_csv("chantiers_dataset.csv")
    X = df[["budget", "progression", "statut"]]
    y = df["jours_restants"]
except Exception as e:
    print(f"Erreur : impossible de lire le dataset - {e}", file=sys.stderr)
    sys.exit(1)

# Vérifier les arguments
if len(sys.argv) == 4:
    try:
        budget = float(sys.argv[1])
        progression = int(sys.argv[2])
        statut = sys.argv[3].strip().capitalize()

        input_data = pd.DataFrame([{
            "budget": budget,
            "progression": progression,
            "statut": statut
        }])

        # Faire la prédiction
        prediction = model.predict(input_data)[0]

        # Calcul de la confiance
        y_pred = model.predict(X)
        mae = mean_absolute_error(y, y_pred)
        confiance = max(0, 1 - mae / y.mean())  # entre 0 et 1

        # Sortie formatée (Qt va parser ça)
        print(f"{int(round(prediction))}|{round(confiance, 2)}")

    except Exception as e:
        print(f"Erreur de prédiction : {e}", file=sys.stderr)
else:
    print("Usage: python predict_duration.py <budget> <progression> <statut>", file=sys.stderr)