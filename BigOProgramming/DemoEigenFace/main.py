import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.metrics import classification_report
from sklearn.decomposition import PCA
from sklearn.svm import SVC

##Helper functions. Use when needed.
def show_orignal_images(pixels):
	#Displaying Orignal Images
	fig, axes = plt.subplots(6, 10, figsize=(11, 7),
	                         subplot_kw={'xticks':[], 'yticks':[]})
	for i, ax in enumerate(axes.flat):
	    ax.imshow(np.array(pixels)[i].reshape(64, 64), cmap='gray')
	plt.show()

def show_eigenfaces(pca):
	#Displaying Eigenfaces
	fig, axes = plt.subplots(3, 8, figsize=(9, 4),
	                         subplot_kw={'xticks':[], 'yticks':[]})
	for i, ax in enumerate(axes.flat):
	    ax.imshow(pca.components_[i].reshape(64, 64), cmap='gray')
	    ax.set_title("PC " + str(i+1))
	plt.show()

#Step 1: Read dataset and visualize it
df = pd.read_csv("face_data.csv")
print(df.head()) #This will print out first few lines of dataset, which transform 64 x 64 pixels into matrix of 1 columns from 0 to 4096
#target identifies the pictures which person


labels = df["target"]
pixels = df.drop(["target"], axis=1)

show_orignal_images(pixels)

#Step 2: Split Dataset into training and testing
x_train, x_test, y_train, y_test = train_test_split(pixels, labels)

#Step 3: Perform PCA
pca = PCA(n_components=200).fit(x_train)

#Plot the variance captured by each component
plt.plot(np.cumsum(pca.explained_variance_ratio_))
plt.show()
show_eigenfaces(pca)

#Step 4: Project Training data to PCA
x_train_pca = pca.transform(x_train)

#Step 5: Initialize Classifier and fit training data
clf = SVC(kernel='rbf', C=1000, gamma=0.01)
clf = clf.fit(x_train_pca, y_train)

#Step 6: Perform testing and get classification report
x_test_pca = pca.transform(x_test)

y_pred = clf.predict(x_test_pca)

print(classification_report(y_test, y_pred))



