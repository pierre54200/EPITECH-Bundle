import streamlit as st

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

st.title("Evolution du projet")

section = st.radio("Etapes du projet : ", ["Kneighbor", "Histgradientboostingclassifier", "Random Forest"])

if section == "Kneighbor":
    st.header("Utilisation de Kneighbor")
    st.write("Le Kneighbor qui regarde les n points les plus proches pour identifier une corélation et faire des prédictions.")
    st.image("images/departure3.png", caption="Retard au départ")
    st.image("images/arrival3.png", caption="Retard à l'arrivée")
    st.image("images/time3.png", caption="Temps de voyage")

elif section == "Histgradientboostingclassifier":
    st.header("Utilisation de Histgradientboostingclassifier")
    st.write("Le Histgradientboostingclassifier qui fait un seul arbre de décision et une regression linéaire et fait des prédictions.")
    st.image("images/departure2.png", caption="Retard au départ")
    st.image("images/arrival2.png", caption="Retard à l'arrivée")
    st.image("images/time2.png", caption="Temps de voyage")

elif section == "Random Forest":
    st.header("Utilisation de Random Forest")
    st.write("Le Random Forest fait un assemblage d'abre de décision pour identifier une corélation et faire des prédictions.")
    st.image("images/departure.png", caption="Retard au départ")
    st.image("images/arrival.png", caption="Retard à l'arrivée")
    st.image("images/time.png", caption="Temps de voyage")