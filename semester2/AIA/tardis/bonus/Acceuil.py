import streamlit as st
import pandas as pd
import pydeck as pdk
from geopy.geocoders import Nominatim
# Header
col1, col2 = st.columns([1, 5])

with col1:
    st.markdown("<div style='margin-top: 10px;'>", unsafe_allow_html=True)
    st.image("images/sncf.png", width=160)

with col2:
    st.markdown("""
        <h1 style='margin-bottom: 0;'>Tardis</h1>
        <p style='color: gray; margin-top: 0;'>Vous ne serez plus jamais en retard avec tardis</p>
    """, unsafe_allow_html=True)

def display_map(departure: object, arrival: object, hour: int, min: int):
    # Geolocalisation
    geolocator = Nominatim(user_agent="Map")

    # Coordinate of both point
    location1 = geolocator.geocode(departure)
    location2 = geolocator.geocode(arrival)

    if location1 and location2: # Only work if path is found
        station_1 = [location1.longitude, location1.latitude]
        station_2 = [location2.longitude, location2.latitude]

        # Center on Paris
        view_state = pdk.ViewState(
            latitude= 46.603354,  # Latitude Paris
            longitude= 1.888334,  # Longitude Paris
            zoom=4, # 4 in order to see every station
            pitch=0
        )

        # Define the coordonate for the line
        line_data = [
            {
                "coordinates": [station_1, station_2]
            }
        ]

        # Define some data for the station
        points_data = [
            {"position": station_1, "name": "Départ"},
            {"position": station_2, "name": "Arrivée"}
        ]

        # Create a layer for the line
        line_layer = pdk.Layer(
            "LineLayer",
            line_data,
            get_source_position="coordinates[0]",  # Departure
            get_target_position="coordinates[1]",  # Arrival
            get_color=[255, 0, 0, 255],  # Red
            get_width=4,  # Ligne width
        )

        # Create a layer for the station
        point_layer = pdk.Layer(
            "ScatterplotLayer",
            points_data,
            get_position="position",  # Station's position
            get_fill_color=[255, 0, 0, 255], # Red
            get_radius=20000,  # Point radius (four time bigger than the line approximatly)
        )
        # Display the map with the line and points
        st.pydeck_chart(pdk.Deck(layers=[line_layer, point_layer], initial_view_state=view_state))



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
    display_map(departure, arrival, hour, min)

    # Give an average global delay for the current trip
    mean_late = group2["Average delay of late trains at departure"].mean() + group2["Average delay of late trains at arrival"].mean()
    st.write(f"Sur cette ligne prévoir en moyenne {mean_late:.0f} minutes en cas de retard")

st.title("Temps de voyage")
st.image("images/time.png", caption="Temps de voyage")