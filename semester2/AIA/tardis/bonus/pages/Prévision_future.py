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

st.title("Prévision future")

section = st.radio("Etapes du projet : ", ["SARIMAX", "PROPHET"])

if section == "SARIMAX":
    st.header("Utilisation de SARIMAX")
    st.image("images/futur.png", caption="Retard")
if section == "PROPHET":
    st.header("Utilisation de PROPHET")
    st.image("images/futur_prophet.png", caption="Retard")

