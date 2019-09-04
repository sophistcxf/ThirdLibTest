"""
Paired categorical plots
========================

"""
import seaborn as sns
import matplotlib.pyplot as plt
sns.set(style="whitegrid")

def describe(titanic):
    print type(titanic)
    print titanic.dtypes
    exit(0)


# Load the example Titanic dataset
titanic = sns.load_dataset("titanic")

#describe(titanic)

# Set up a grid to plot survival probability against several variables
g = sns.PairGrid(titanic, y_vars="survived",
                 x_vars=["class", "sex", "who", "alone"],
                 height=5, aspect=.5)

# Draw a seaborn pointplot onto each Axes
g.map(sns.pointplot, scale=1.3, errwidth=4, color="xkcd:plum")
g.set(ylim=(0, 1))
sns.despine(fig=g.fig, left=True)
plt.show()