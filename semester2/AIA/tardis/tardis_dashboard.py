import streamlit as st
import pandas as pd

# Make a dictionnary for every train station name
dico_station = pd.read_csv("station.csv")["Station"].to_numpy()

# Read the train station csv
df = pd.read_csv("cleaned_dataset.csv")

st.title("Outil d'étude des retards de la SNCF")

delays = df["Pct of delay train"].head(20).mean()

# Message to prevent the user if there are delay the last few days

if (delays <= 40):
    st.success("Très peu de retard ces derniers jours")

if (delays > 40 and delays <= 60):
    st.info("Peu de retard ces derniers jours")

if (delays > 60 and delays <= 80):
    st.warning("Beaucoup de retard ces derniers jours !!!")

if (delays > 80):
    st.error("Enormément de retard ces derniers jours !!!")

# Select only possible departure station
departure = st.selectbox("Choisir la station de départ", sorted(dico_station))


# Make the list of departure station in an index matrix and then only take them in a dataframe
index = df.index[df["Departure station"] == departure].to_numpy()
group = df.iloc[index]

# Select only possible departure station
arrival = st.selectbox("Choisir la station de d'arriver", sorted(group["Arrival station"].unique()))

# Make the list of arrival station in an index matrix and then only take them in a dataframe
index2 = group.index[group["Arrival station"] == arrival].to_numpy()
group2 = df.iloc[index2]

# If exist calculate the mean traject time
if group.any().any() and group2.any().any():
    mean = group["Average journey time"].mean()

    # Time formatting
    hour = mean // 60
    min = mean % 60

    st.success(f"{departure} -- > {arrival} temps de trajet moyen {int(hour)}h {int(min)}min")

# Give an average global delay for the current trip
mean_late = group2["Average delay of late trains at departure"].mean() + group2["Average delay of late trains at arrival"].mean()
st.write(f"Sur cette ligne prévoir en moyenne {mean_late:.0f} minutes en cas de retard")