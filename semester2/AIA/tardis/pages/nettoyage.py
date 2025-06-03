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

st.title("Nettoyage des données")

st.header("Nettoyage des dates")
st.write("Nous avons commencé par nettoyer toutes les dates qui n'étais pas dans le bon format pour ensuite enlever celle qui n'étais pas dans la bonne période de temps.")

st.header("Nettoyage des gares")
st.write("Nous avons ensuite nettoyer toutes les colomnes avec des mot dedans comme les colomnes stations ou nous avons changer les gares qui n'avait pas le bon nom en les corrigeant.")

st.header("Nettoyage des valeurs")
st.write("Nous avons fini par nettoyer toutes les valeurs qui ne sont pas cooérentes comme des nombres de train avec des virgules, des temps de trajet trop long, ou des pourcentages négatif ou suppérieur à 100%.")