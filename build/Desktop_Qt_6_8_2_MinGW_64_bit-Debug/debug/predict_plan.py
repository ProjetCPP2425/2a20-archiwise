import sys
import tensorflow as tf
from tensorflow.keras.preprocessing import image
import numpy as np

# Vérification d'arguments
if len(sys.argv) < 2:
    print("Usage: python predict_plan.py <image_path>")
    sys.exit()

# Charger le modèle entraîné
model = tf.keras.models.load_model("plan_detector_finetuned.h5")

# Charger et préparer l'image
img_path = sys.argv[1]
img = image.load_img(img_path, target_size=(224, 224))
img_array = image.img_to_array(img) / 255.0
img_array = np.expand_dims(img_array, axis=0)

# Prédiction
prediction = model.predict(img_array)

# Affichage du résultat
if prediction[0][0] > 0.5:
    print("valid")   # L'image est un plan
else:
    print("invalid") # L'image n'est pas un plan
