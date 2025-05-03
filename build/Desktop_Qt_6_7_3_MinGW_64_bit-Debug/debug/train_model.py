# train_model.py
import pandas as pd
import joblib
from sklearn.ensemble import RandomForestRegressor
from sklearn.compose import ColumnTransformer
from sklearn.preprocessing import OneHotEncoder
from sklearn.pipeline import make_pipeline

# Charger le dataset
df = pd.read_csv("chantiers_dataset.csv")

# Features et target
X = df[["budget", "progression", "statut"]]
y = df["jours_restants"]

# Encodage + modèle
preprocessor = ColumnTransformer([
    ("statut_enc", OneHotEncoder(), ["statut"])
], remainder="passthrough")

pipeline = make_pipeline(preprocessor, RandomForestRegressor(n_estimators=100, random_state=42))
pipeline.fit(X, y)

# Sauvegarder le modèle entraîné
joblib.dump(pipeline, "modele_chantier.joblib")