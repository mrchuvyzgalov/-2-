import numpy as np
import matplotlib.pyplot as plt

try:
    myfile = open('../files/table.txt', "r")

    lines = myfile.readlines()

    xright, xleft = [int(i) for i in lines[0].split()]

    x = [i for i in range(xright, xleft + 1)]

    fig = []
    ax = []

    for i in range(0, int(lines[1]) * 2, 2):
        new_fig, new_ax = plt.subplots()

        new_ax.set_xlim(xright, xleft)
        
        title, xlabel, ylabel = lines[i + 2].split()

        new_ax.set_title(title)

        new_ax.set_xlabel(xlabel)
        new_ax.set_ylabel(ylabel)

        y = [int(i) for i in lines[i + 3].split()]

        new_ax.bar(x, y, color="green")

        fig.append(new_fig)
        ax.append(new_ax)


    myfile.close()


    plt.style.use('seaborn-whitegrid')

    for i in range(len(fig)):
        fig[i].savefig('../files/' + ax[i].get_title() + '.png')

    print('Files were created successfully\n')

except:
    print('ERROR: file was not found or file was not filled correctly\n')
