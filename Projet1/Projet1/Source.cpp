#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <set>
#include "windows.h"

using namespace std;
void genome(double qte_m, double qte_m_exp, double qte_atcg, double qte_atcg_exp) {
	std::random_device rd;
	std::mt19937 gen(rd());

	// if particles decay once per second on average,
	// how much time, in seconds, until the next one?
	std::exponential_distribution<> d(1);
	set<string> res;
	int i = (int)round(qte_m_exp * d(gen) + qte_m);
	for (; i > 0; i--) {
		string r;
		do {
			r = "";
			for (int j = (int)round(qte_atcg_exp * d(gen) + qte_atcg); j > 0; j >>= 2) {
				r += (j & 1 ? (j & 2 ? 'A' : 'T') : (j & 2 ? 'C' : 'G'));
			}
		} while (res.find(r) != res.end());
		res.insert(r);
		cout <<r<< ';';
	}
	cout << endl;
}
void dico(set<string> maladies, double qte_m, double qte_m_exp, double qte_atcg, double qte_atcg_exp) {
	for (auto n = maladies.begin(); n!= maladies.end(); n++) {
		cout << *n << ";";
		genome(qte_m, qte_m_exp, qte_atcg, qte_atcg_exp);
	}
	
}

int main() {
	set<string> test = { "Agoraphobie", "Anorexie", "Anorexie mentale", "Anxiete de separation", "Autisme atypique", "Automutilation", "Autophagie", "cognitif", "Depression clinique", "Depression perinatale", "Depression saisonniere", "Dyscalculie", "Dysmorphophobie", "Dyslexie", "Echolalie", "Echopraxie", "Ejaculation precoce", "Encopresie", "Episode hypomaniaque", "Exhibitionnisme", "Maladie d'Alzheimer", "Maladie de Gilles de la Tourette", "Manie", "Megalomanie", "Melancolie", "Paraphilie", "Parasomnie", "Pedophilie", "Perfectionnisme", "Peur panique", "Phobie sociale", "Pica", "Psychose infantile", "Pyromanie", "Schizophrenie", "Schizophrenie catatonique", "Sinistrose", "Somnambulisme", "Syndrome d'alcoolisation foetale", "Syndrome d'Angelman", "Syndrome d'Asperger", "Syndrome de Down", "Syndrome d'Ekbom", "Syndrome de Fregoli", "Syndrome de Ganser", "Syndrome de Joubert", "Syndrome de Munchhausen", "Syndrome de Munchhausen par procuration", "Syndrome general d'adaptation", "Syndrome de Peter Pan", "Syndrome de Williams", "Terreur nocturne", "Tic", "Trichotillomanie", "Trouble amnesique", "Trouble anxieux", "Trouble autistique", "Trouble bipolaire", "Trouble catatonique", "Trouble cognitif", "Trouble d'apprentissage", "Trouble de l'adaptation", "Trouble de la personnalite", "Trouble de la personnalite anankastique", "Trouble de la personnalite antisociale", "Trouble de la personnalite borderline", "Trouble de la personnalite dependante", "Trouble de la personnalite evitante", "Trouble de la personnalite histrionique", "Trouble de la personnalite narcissique", "Trouble de la personnalite paranoiaque", "Trouble de la personnalite schizotypique", "Trouble des habitudes et des impulsions", "Trouble du deficit de l'attention", "Trouble du spectre de l'alcoolisation foetale", "Trouble de stress post-traumatique", "Trouble emotionnel", "Trouble erectile masculin", "Trouble psychotique bref", "Trouble psychotique partage", "hallucinogenes", "alcool", "cocaine", "cafeine", "cannabis", "amphetamines", "Trouble obsessionnel compulsif", "Trouble schizo-affectif" };
	cout << "----------------------------- DICO --------------------------" << endl;
	dico(test, 1, 5, 1, 32);
	cout << "----------------------------- DICO --------------------------" << endl;
	cout << "----------------------------- GENOMES --------------------------" << endl;
	for (int i = 1; i <= 10; i++) {
		cout << "GENOME " << to_string(i) << " :" <<endl;
		genome(20, 70, 2, 64);
	}
	cout << "----------------------------- GENOMES --------------------------" << endl;
	return 0;
}