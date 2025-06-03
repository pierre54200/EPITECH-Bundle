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

st.title("Analyse des retards")

section = st.radio("Prédictions sur : ", ["Départ", "Arrivée", "Temps de trajet"])

if section == "Départ":
    st.header("Prédictions vs valeurs réels des retards des trains au départ")
    st.image("images/departure.png", caption="Retard au départ")
elif section == "Arrivée":
    st.header("Prédictions vs valeurs réels des retards des trains à l'arrivée")
    st.image("images/arrival.png", caption="Retard à l'arrivée")
elif section == "Temps de trajet":
    st.header("Prédictions vs valeurs réels des temps de trajet")
    st.image("images/delay.png", caption="Retard")