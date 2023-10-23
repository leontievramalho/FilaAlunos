#include <iostream>

using namespace std;

struct No{
	string conteudo;
	No *next;
};

void insertConteudoFim(No *&head, string conteudo){
	No *novoConteudo = new No;
	novoConteudo -> conteudo = conteudo;
	novoConteudo -> next = NULL;
	if(head == NULL){
		head = novoConteudo;
		return;
	}
	No *atual = head;
	while(atual -> next != NULL){
		atual = atual -> next;
	}
	atual -> next = novoConteudo;
};

void exibirListaConteudo(No *&head){
	No *atual = head;
	cout << "[ ";
	while(atual != NULL){
		cout << atual -> conteudo << ", ";
		atual = atual -> next;
	}
	cout << "]" << endl;
}

void exibirListaConteudoCompleta(No *&head){
	No *atual = head;
	cout << "[ ";
	while(atual != NULL){
		cout << atual -> conteudo << ", ";
		atual = atual -> next;
	}
	cout << "]";
}

struct Disciplina{
	string nome;
	int creditos;
	No *listaConteudo;
	
	void addConteudo(string conteudo){
		insertConteudoFim(listaConteudo, conteudo);
	}
	void removerConteudo(string conteudo){
		No *atual = listaConteudo;
		No *anterior = NULL;
		while(atual != NULL && atual -> conteudo != conteudo){
			anterior = atual;
			atual = atual -> next;
		}
		if(atual == NULL){
			cout << "Disciplina nao encontrada." << endl;
			return;
		}
		if(anterior == NULL){
			listaConteudo = atual -> next;
			delete atual;
			return;
		}
		anterior -> next = atual -> next;
		delete atual;
	}
	void exibirConteudos(){
		exibirListaConteudo(listaConteudo);
	}
	void exibirConteudosCompletos(){
		exibirListaConteudoCompleta(listaConteudo);
	}
};

struct NoDisciplina{
	Disciplina disciplina;
	NoDisciplina *next;
};

void insertDisciplinaFim(NoDisciplina *&head, Disciplina disciplina){
	NoDisciplina *novaDisciplina = new NoDisciplina;
	novaDisciplina -> disciplina = disciplina;
	novaDisciplina -> next = NULL;
	if(head == NULL){
		head = novaDisciplina;
		return;
	}
	NoDisciplina *atual = head;
	while(atual -> next != NULL){
		atual = atual -> next;
	}
	atual -> next = novaDisciplina;
};

void exibirListaDisciplina(NoDisciplina *&head){
	NoDisciplina *atual = head;
	cout << "[ ";
	while(atual != NULL){
		cout << atual -> disciplina.nome << ", ";
		atual = atual -> next;
	}
	cout << "]" << endl;
}

struct Aluno{
	string nome;
	string cpf;
	int idade;
	string matricula;
	NoDisciplina *listaDisciplina;
	
	void addDisciplina(Disciplina disciplina){
		insertDisciplinaFim(listaDisciplina, disciplina);
	}
	void removerDisciplina(Disciplina disciplina){
		NoDisciplina *atual = listaDisciplina;
		NoDisciplina *anterior = NULL;
		while(atual != NULL && atual -> disciplina.nome != disciplina.nome){
			anterior = atual;
			atual = atual -> next;
		}
		if(atual == NULL){
			cout << "Disciplina nao encontrada." << endl;
			return;
		}
		if(anterior == NULL){
			listaDisciplina = atual -> next;
			delete atual;
			return;
		}
		anterior -> next = atual -> next;
		delete atual;
	}
	
	void listarDisciplinas(){
		exibirListaDisciplina(listaDisciplina);
	}
	void listarDisciplinasCompleto(){
		NoDisciplina *atual = listaDisciplina;
		cout << "[ ";
		while(atual != NULL){
			cout << "[" << atual -> disciplina.nome << ": ";
			atual -> disciplina.exibirConteudosCompletos();
			cout << "], ";
			atual = atual -> next;
		}
		cout << "]";
	}
};

struct ItemFilaAluno{
	Aluno aluno;
	ItemFilaAluno *next;
};

void enqueue(ItemFilaAluno *&head, Aluno aluno){
	ItemFilaAluno *novoAluno = new ItemFilaAluno;
	novoAluno -> aluno = aluno;
	novoAluno -> next = NULL;
	if(head == NULL){
		head = novoAluno;
		return;
	}
	ItemFilaAluno *atual = head;
	while(atual -> next != NULL){
		atual = atual -> next;
	}
	atual -> next = novoAluno;
};

void dequeue(ItemFilaAluno *&head){
	if(head == NULL){
		cout << "fila vazia";
		return;
	}
	ItemFilaAluno *aux = head;
	delete head;
	head = aux -> next;
	
};

bool isEmpty(ItemFilaAluno *&head){
	return (head == NULL);
}

void exibirFilaAluno(ItemFilaAluno *&head){
	ItemFilaAluno *atual = head;
	cout << "[ ";
	while(atual != NULL){
		cout << atual -> aluno.nome << ", ";
		atual = atual -> next;
	}
	cout << "]" << endl;
}

void exibirFilaAlunoCompleta(ItemFilaAluno *&head){
	ItemFilaAluno *atual = head;
	cout << "[ ";
	while(atual != NULL){
		cout << "["<< atual -> aluno.nome << ": ";
		atual -> aluno.listarDisciplinasCompleto();
		cout << "], " ;
		atual = atual -> next;
	}
	cout << "]" << endl;
}

void front(ItemFilaAluno *&head){
	if(head == NULL){
		cout << "fila vazia";
		return;
	}
	cout << head -> aluno.nome << endl;
} 

int size(ItemFilaAluno *head){
	int count = 0;
	while(head != NULL){
		count ++;
		head = head -> next;
	}
	return count;
}


int main() {
	//lista conteudos	
	No *listConteudos = NULL;
	insertConteudoFim(listConteudos, "Geometria");
	insertConteudoFim(listConteudos, "Aritmetica");
	insertConteudoFim(listConteudos, "Algebra");
	insertConteudoFim(listConteudos, "Trigonometria");
	cout << "Lista de conteudos 1: ";
	exibirListaConteudo(listConteudos);
	
	No *listConteudos2 = NULL;
	insertConteudoFim(listConteudos2, "C++");
	insertConteudoFim(listConteudos2, "Vetor");
	insertConteudoFim(listConteudos2, "Matrizes");
	insertConteudoFim(listConteudos2, "Ordenacao");
	cout << "Lista de conteudos 2: ";
	exibirListaConteudo(listConteudos2);
	
	No *listConteudos3 = NULL;
	insertConteudoFim(listConteudos3, "Modelo Conceitual");
	insertConteudoFim(listConteudos3, "Entidade");
	insertConteudoFim(listConteudos3, "Relacionamento");
	insertConteudoFim(listConteudos3, "ModeloLogico");
	cout << "Lista de conteudos 3: ";
	exibirListaConteudo(listConteudos3);
	
	No *listConteudos4 = NULL;
	insertConteudoFim(listConteudos4, "Cores");
	insertConteudoFim(listConteudos4, "Filtro");
	insertConteudoFim(listConteudos4, "Binarizacao");
	insertConteudoFim(listConteudos4, "Histograma");
	cout << "Lista de conteudos 4: ";
	exibirListaConteudo(listConteudos4);
	
	//disciplinas
	Disciplina matematica;
	matematica.nome = "Matematica";
	matematica.creditos = 5;
	matematica.listaConteudo = listConteudos;
	
	Disciplina estruturaDados;
	estruturaDados.nome = "Estrutura de Dados";
	estruturaDados.creditos = 6;
	estruturaDados.listaConteudo = listConteudos2;
	
	Disciplina bancoDados;
	bancoDados.nome = "Banco de Dados";
	bancoDados.creditos = 5;
	bancoDados.listaConteudo = listConteudos3;
	
	Disciplina processamentoImagem;
	processamentoImagem.nome = "Processamento Digital de Imagens";
	processamentoImagem.creditos = 4;
	processamentoImagem.listaConteudo = listConteudos4;
	
	//lista de disciplinas
	
	NoDisciplina *listDisciplina = NULL;
	insertDisciplinaFim(listDisciplina, matematica);
	insertDisciplinaFim(listDisciplina, estruturaDados);
	cout << "Lista de disciplinas 1: ";
	exibirListaDisciplina(listDisciplina);
	
	NoDisciplina *listDisciplina2 = NULL;
	insertDisciplinaFim(listDisciplina2, bancoDados);
	insertDisciplinaFim(listDisciplina2, processamentoImagem);
	cout << "Lista de disciplinas 2: ";
	exibirListaDisciplina(listDisciplina2);
	
	//Alunos
	Aluno aluno1;
	aluno1.nome = "Joao";
	aluno1.cpf = "12312353434";
	aluno1.idade = 23;
	aluno1.matricula = "3124343434";
	aluno1.listaDisciplina = listDisciplina;
	
	Aluno aluno2;
	aluno2.nome = "Maria";
	aluno2.cpf = "3487298442";
	aluno2.idade = 19;
	aluno2.matricula = "394839483";
	aluno2.listaDisciplina = listDisciplina2;
	
	//Fila de alunos
	cout << "Fila vazia: ";
	ItemFilaAluno *filaAluno = NULL;
	exibirFilaAluno(filaAluno);
	
	cout << "Size: " << size(filaAluno) << endl;
	
	cout << "Enqueue: ";
	enqueue(filaAluno, aluno1);
	exibirFilaAluno(filaAluno);
	
	cout << "Size: " << size(filaAluno) << endl;
	
	cout << "Enqueue: ";
	enqueue(filaAluno, aluno2);
	exibirFilaAluno(filaAluno);
	
	cout << "Size: " << size(filaAluno) << endl;
	
	cout << "Front: ";
	front(filaAluno);
	
	cout << "Dequeue: ";
	dequeue(filaAluno);
	exibirFilaAluno(filaAluno);
	
	cout << boolalpha;
	
	cout << "fila vazia? "<< isEmpty(filaAluno) << endl;
	
	cout << "Dequeue: ";
	dequeue(filaAluno);
	exibirFilaAluno(filaAluno);
	
	cout << "fila vazia? "<< isEmpty(filaAluno) << endl;
	
	cout << "Exibir disciplinas de aluno 1: ";
	aluno1.listarDisciplinas();
	aluno1.addDisciplina(bancoDados);
	cout << "Add disciplina: ";
	aluno1.listarDisciplinas();
	cout << "Remover disciplina: ";
	aluno1.removerDisciplina(matematica);
	aluno1.listarDisciplinas();
	cout << "listar conteudos de Banco de dados: ";
	bancoDados.exibirConteudos();
	bancoDados.addConteudo("mySQL");
	cout << "add Conteudo: ";
	bancoDados.exibirConteudos();
	cout << "remover Conteudo: ";
	bancoDados.removerConteudo("Entidade");
	bancoDados.exibirConteudos();
	cout << "Enqueue: ";
	enqueue(filaAluno, aluno1);
	exibirFilaAluno(filaAluno);
	cout << "Enqueue: ";
	enqueue(filaAluno, aluno2);
	exibirFilaAluno(filaAluno);
	cout << "Fila aluno com todas as informacoes: " << endl;
	exibirFilaAlunoCompleta(filaAluno);
	return 0;
}
