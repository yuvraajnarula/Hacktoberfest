
#Exploratory Data Analysis
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns

from sklearn.datasets import load_iris

iris=load_iris()

X=pd.DataFrame(iris['data'],columns=iris['feature_names'])

y=pd.DataFrame(iris['target'],columns=['target'])

df=X.join(y)

df['target'].replace(dict(zip(range(len(iris['target_names'])), iris['target_names'])), inplace=True)

​


df.columns=['sepal_length', 'sepal_width', 'petal_length','petal_width', 'species']


print(df.shape)
print(df.columns)
df['species'].value_counts()


setosa=df.loc[df["species"]=="setosa"]
versicolor=df.loc[df["species"]=="versicolor"]
virginica=df.loc[df["species"]=="virginica"]

df.plot(kind='scatter',x="sepal_length",y="sepal_width")



sns.set_style("whitegrid")
sns.FacetGrid(df,hue="species",height=4).map(plt.scatter,"sepal_length","sepal_width").add_legend()
plt.show()


sns.set_style("whitegrid")
sns.pairplot(df,hue="species",height=3)
sns.boxplot(x="species",y="petal_length",data=df)
plt.show()

​
